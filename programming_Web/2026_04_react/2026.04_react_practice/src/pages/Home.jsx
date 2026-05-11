import { useNavigate } from "react-router-dom"

function Home() {
    const navigate = useNavigate()

    const goToAbout = () => {
        navigate('/about')
    }

    const goToContact = () => {
        navigate('/contact')
    }

    const goToUser = (id) => {
        navigate(`/user/${id}`)
    }

    return (
        <div style={{ textAlign: 'center', marginTop: '50px' }}>
            <h1>🏠 HOME PAGE</h1>
            <p>React Router learning...</p>

            <div style={{ display: 'flex', gap: '10px', justifyContent: 'center', marginTop: '20px' }}>
                <button onClick={goToAbout} style={buttonStyle}>
                    Go to Intro page
                </button>
                <button onClick={goToContact} style={buttonStyle}>
                    Go to Contact page
                </button>

                <button onClick={() => goToUser(1)} style={buttonStyle}>
                    👤 사용자 1번 보기
                </button>
                <button onClick={() => goToUser(2)} style={buttonStyle}>
                    👤 사용자 2번 보기
                </button>
            </div>
        </div>
    )
}

const buttonStyle = {
  padding: '10px 20px',
  fontSize: '16px',
  cursor: 'pointer',
  backgroundColor: '#007bff',
  color: 'white',
  border: 'none',
  borderRadius: '5px'
}

export default Home