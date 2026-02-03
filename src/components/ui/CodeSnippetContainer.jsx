'use client'

import { useState } from "react";
import { Copy } from "lucide-react";
import { Button } from "@/components/ui/button";

export default function CodeSnippetContainer({ code, language = "javascript" }) {
  const [copied, setCopied] = useState(false);

  const handleCopy = async () => {
    await navigator.clipboard.writeText(code);
    setCopied(true);
    setTimeout(() => setCopied(false), 2000);
  };

  return (
    <div className="relative bg-neutral-900 text-white rounded-2xl p-4 shadow-lg border border-neutral-700 overflow-hidden">
      <div className="flex justify-between items-center mb-2">
        <span className="text-sm text-neutral-400 uppercase">{language}</span>
        <Button
          variant="ghost"
          size="sm"
          onClick={handleCopy}
          className="text-neutral-300 hover:text-white"
        >
          {copied ? "Copied!" : <Copy size={16} />}
        </Button>
      </div>

      <pre className="overflow-x-auto font-mono text-sm">
        <code>{code}</code>
      </pre>
    </div>
  );
}
