const INITIAL_DATA = {
  text: "Hello World"
};

const HelloWorldReducer = (state = INITIAL_DATA, action) => {
  switch (action.type) {
    default:
      return state;
  }
};

export default HelloWorldReducer;
