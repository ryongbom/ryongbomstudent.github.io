import useInput from "./hooks/useInput";
import useToggle from "./hooks/useToggle";

function App() {
  const name = useInput('')
  const email = useInput('')
  const isDark = useToggle(false)

  const handleSubmit = (e) => {
    e.preventDefault()

    console.log('Name:', name.value)
    console.log('Email:', email.value)
    name.reset()
    email.reset()
  }

  return (
    <div style={{
      backgroundColor: isDark.value ? '#333' : '#fff',
      color: isDark.value ? '#fff' : '#000',
      minHeight: '90vh',
      padding: '20px'
    }}>
      <button type="button" onClick={() => {isDark.toggle()}} style={buttonStyle}>
        {isDark.value ? '☀️ lightMode' : '🌙 DarkMode'}
      </button>
      <div style={{ padding: '20px', maxWidth: '700px', margin: '0 auto' }}>
        <h1 style={{ color: isDark.value ? '#fff' : '#000' }}>useInput Practice</h1>

        <form onSubmit={handleSubmit}>
          <div>
            <label>Name:</label>
            <input
              type="text"
              {...name}  // value={name.value} onChange={name.onChange} 와 동일
              placeholder="Enter your name..."
              style={inputStyle}
            />
          </div>

          <div>
            <label>Email:</label>
            <input
              type="email"
              {...email}
              placeholder="Enter your email..."
              style={inputStyle}
            />
          </div>

          <button type="submit" style={buttonStyle}>Send</button>
          <button type="button" onClick={() => { name.reset(), email.reset() }} style={resetStyle}>
            Reset
          </button>
        </form>

        <div style={{ marginTop: '20px' }}>
          <p>RealTime preview:</p>
          <p>Name: {name.value}</p>
          <p>Email: {email.value}</p>
        </div>
      </div>
    </div>
  )
}

const inputStyle = {
  width: '100%',
  padding: '8px',
  margin: '10px 0',
  boxSizing: 'border-box'
}

const buttonStyle = {
  padding: '8px 16px',
  marginRight: '10px',
  backgroundColor: '#007bff',
  color: 'white',
  border: 'none',
  borderRadius: '4px',
  cursor: 'pointer'
}

const resetStyle = {
  padding: '8px 16px',
  backgroundColor: '#dc3545',
  color: 'white',
  border: 'none',
  borderRadius: '4px',
  cursor: 'pointer'
}

export default App