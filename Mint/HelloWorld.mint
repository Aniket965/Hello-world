component Main {
  style base {
    font-family: sans;
    font-weight: bold;
    font-size: 50px;

    justify-content: center;
    align-items: center;
    display: flex;
    height: 100vh;
  }

  fun render : Html {
    <div::base>
      <{ "Hello World!" }>
    </div>
  }
}
