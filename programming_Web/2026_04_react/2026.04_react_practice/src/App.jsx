import { BrowserRouter, Routes, Route, Link } from "react-router-dom";
import Home from "./pages/Home";
import About from "./pages/About";
import Contact from "./pages/Contact";
import NotFound from "./pages/NotFound";
import UserDetail from "./pages/UserDetail";
import History from "./pages/History";
import Team from "./pages/Team";

function App() {
  return (
    <BrowserRouter>
      <nav style={{ 
        padding: '10px', 
        backgroundColor: '#007bff',
        display: 'flex',
        gap: '20px',
        justifyContent: 'center'
      }}>
        <Link to="/" style={{ color: 'white', textDecoration: 'none' }}>🏠 Home</Link>
        <Link to="/about" style={{ color: 'white', textDecoration: 'none' }}>About</Link>
        <Link to="/contact" style={{ color: 'white', textDecoration: 'none' }}>Contact</Link>
      </nav>

      <Routes>
        <Route path="/" element={<Home />} />
        <Route path="/about" element={<About />}>
          <Route path="team" element={<Team />} />
          <Route path="history" element={<History />} />
        </Route>
        <Route path="/contact" element={<Contact />} />
        <Route path="/user/:userId" element={<UserDetail />} />
        <Route path="*" element={<NotFound />} />
      </Routes>
    </BrowserRouter>
  )
}

export default App