"use client"

import Link from "next/link"
import {
  Home,
  Info,
  Compass,
  Mail,
  BarChart2,
  Search,
} from "lucide-react"

export default function Navbar() {
  return (
    <header className="fixed top-0 left-0 w-full h-16 bg-white border-b border-gray-200 z-50">
      <div className="grid grid-cols-3 items-center h-full px-8">
        

        {/* CENTER: Navigation */}
        <nav className="justify-self-center flex items-center gap-8 text-sm font-medium text-black">
          <Link href="/" className="flex items-center gap-2 hover:text-gray-500">
            <Home size={16} /> Home
          </Link>
          <Link href="/about" className="flex items-center gap-2 hover:text-gray-500">
            <Info size={16} /> About
          </Link>
          <Link href="/overview" className="flex items-center gap-2 hover:text-gray-500">
            <Compass size={16} /> Overview
          </Link>
          <Link href="/benchmark" className="flex items-center gap-2 hover:text-gray-500">
            <BarChart2 size={16} /> Benchmark
          </Link>
          <Link href="/contactus" className="flex items-center gap-2 hover:text-gray-500">
            <Mail size={16} /> Contact
          </Link>
        </nav>
      </div>
    </header>
  )
}
