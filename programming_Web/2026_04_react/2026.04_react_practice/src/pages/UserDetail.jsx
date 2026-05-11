import { useParams, useNavigate } from "react-router-dom";

function UserDetail() {
    const { userId } = useParams()
    const navigate = useNavigate()

    return (
        <div style={{ textAlign: 'center', marginTop: '50px' }}>
            <h1>👤 사용자 상세 페이지</h1>
            <p>사용자 ID: <strong>{userId}</strong></p>
            <button onClick={() => navigate(-1)} style={buttonStyle}>
                Go to Back
            </button>
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
  borderRadius: '5px',
  marginTop: '20px'
}

export default UserDetail