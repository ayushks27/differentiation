#include <crow.h>
#include <nlohmann/json.hpp>
#include "../benchmark/BenchmarkEngine.h"

void startServer() {
    crow::SimpleApp app;
    
    CROW_ROUTE(app, "/")
    ([] {
        return crow::response{
            200,
            "Backend is running"
            "Available endpoints:"
            "➡ http://localhost:8080/benchmark"
        };
    });
    
    CROW_ROUTE(app, "/health")
    ([] {
        return crow::response{200, "OK"};
    });

    CROW_ROUTE(app, "/benchmark")
    .methods(crow::HTTPMethod::GET, crow::HTTPMethod::OPTIONS)
    ([](const crow::request& req, crow::response& res) {

        // ✅ CORS HEADERS (REQUIRED)
        res.add_header("Access-Control-Allow-Origin", "*");
        res.add_header("Access-Control-Allow-Methods", "GET, OPTIONS");
        res.add_header("Access-Control-Allow-Headers", "Content-Type");

        // ✅ Handle browser preflight request
        if (req.method == crow::HTTPMethod::OPTIONS) {
            res.code = 204; // No Content
            res.end();
            return;
        }
        
        // ✅ Actual benchmark logic
        auto results = BenchmarkEngine::runAll(100000);

        nlohmann::json response = nlohmann::json::array();
        for (auto& r : results) {
            response.push_back({
                {"name", r.name},
                {"category", r.category},
                {"inputSize", r.inputSize},
                {"avgMs", r.avgMs},
                {"minMs", r.minMs},
                {"maxMs", r.maxMs}
            });
        }

        res.code = 200;
        res.write(response.dump(2));
        res.end();
    });

    app.port(8080).multithreaded().run();
}
