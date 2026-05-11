import { useState, useContext, createContext } from 'react'

const userContext = createContext()

function App() {
  const [user, setUser] = useState({
    name: 'danial',
    level: 'VIP',
    point: 1250
  })

  console.log('🔴 App rendering')

  return (
    <userContext.Provider value={user}>
      <div style={{ padding: '20px' }}>
        <h1>props drilling Practice</h1>
        <p>아래로 user data가 계속 전달됩니다</p>
        <hr />
        <MainLayout />
      </div>
    </userContext.Provider>
  )
}

function MainLayout() {
  console.log('🟠 MainLayout Randering - user 필요 없음!')
  
  return (
    <div style={{ border: '2px solid orange', padding: '15px', margin: '10px 0' }}>
      <h3>📐 MainLayout (Layout 담당)</h3>
      <p>이 Component는 user data가 필요 없음</p>
      <ContentArea />
    </div>
  )
}

function ContentArea() {
  console.log('🟡 ContentArea Rendering - user 필요 없음!')
  
  return (
    <div style={{ border: '2px solid gold', padding: '15px', margin: '10px 0' }}>
      <h3>📄 ContentArea (내용 령역)</h3>
      <p>이 컴포넌트도 user 데이터가 필요 없음</p>
      <UserProfile />
    </div>
  )
}

function UserProfile() {
  console.log('🟢 UserProfile Rendering - 드디어 user 필요!')
  const user = useContext(userContext)
  
  return (
    <div style={{ border: '2px solid green', padding: '15px', margin: '10px 0' }}>
      <h3>👤 UserProfile (여기서 진짜 필요!)</h3>
      <p><strong>이름:</strong> {user.name}</p>
      <p><strong>등급:</strong> {user.level}</p>
      <p><strong>포인트:</strong> {user.point}</p>
      <ProfileActions />
    </div>
  )
}

function ProfileActions() {
  console.log('🔵 ProfileActions Rendering - user 또 필요!')
  const user = useContext(userContext)
  
  return (
    <div style={{ border: '2px solid blue', padding: '15px', margin: '10px 0' }}>
      <h3>⚙️ ProfileActions</h3>
      <p>포인트: {user.point}점</p>
      <button onClick={() => alert(`${user.name}, ~~~~`)}>
        로그아웃
      </button>
    </div>
  )
}

export default App