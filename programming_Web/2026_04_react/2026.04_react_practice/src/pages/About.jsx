import { Outlet, Link } from "react-router-dom"

function About() {
    return (
        <div style={{ textAlign: 'center', marginTop: '50px' }}>
            <h1>📖  INTRODUCTION PAGE</h1>

            <div style={{ display: 'flex', gap: '20px', justifyContent: 'center', margin: '20px 0' }}>
                <Link to="/about/team" style={{ color: '#007bff' }}>👥 팀 소개</Link>
                <Link to="/about/history" style={{ color: '#007bff' }}>📜 연혁</Link>
            </div>
            
            <div style={{ 
                border: '1px solid #ccc', 
                borderRadius: '10px', 
                padding: '20px',
                marginTop: '20px'
            }}>
                <Outlet />
            </div>

            <p>This is React Router example.</p>
        </div>
    )
}

export default About