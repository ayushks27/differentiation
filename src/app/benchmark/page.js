"use client";

import { useEffect, useState } from "react";
import { BACKEND_URL } from "@/config/backend";

export default function BenchmarkPage() {
  const [results, setResults] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);

  useEffect(() => {
  fetch(`${BACKEND_URL}/benchmark`)
    .then((res) => {
      if (!res.ok) throw new Error("Backend error");
      return res.json();
    })
    .then((data) => {
      setResults(data);
      setLoading(false);
    })
    .catch((err) => {
      console.error(err);
      setError("Failed to fetch benchmark data");
      setLoading(false);
    });
  }, []);

  if (loading) return <p style={{ textAlign: "center" }}>Running benchmarks…</p>;
  if (error) return <p style={{ color: "red", textAlign: "center" }}>{error}</p>;

  return (
    <div style={{ padding: "2rem", width: "100%" }}>
      <h2>Benchmark Results</h2>
      <br></br>
      <table style={{ width: "100%", borderCollapse: "collapse" }}>
        <thead>
          <tr style={{ textAlign: "left", borderBottom: "1px solid #ddd" }}>
            <th>Algorithm</th>
            <th>Category</th>
            <th>Input Size</th>
            <th>Avg (ms)</th>
            <th>Min (ms)</th>
            <th>Max (ms)</th>
          </tr>
        </thead>

        <tbody>
          {results.map((r, i) => (
            <tr key={i} style={{ borderBottom: "1px solid #f0f0f0" }}>
              <td>{r.name}</td>
              <td>{r.category}</td>
              <td>{r.inputSize}</td>
              <td>{r.avgMs.toFixed(3)}</td>
              <td>{r.minMs.toFixed(3)}</td>
              <td>{r.maxMs.toFixed(3)}</td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
}
