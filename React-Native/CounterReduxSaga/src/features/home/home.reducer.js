import HomeTypes from './home.types';

const initState = {
  number: 0,
};

export const HomeReducer = (state = initState, action) => {
  switch (action.type) {
    case HomeTypes.HOME_INCREMENT:
      return { ...state, number: state.number + 1 };
    case HomeTypes.HOME_DECREMENT:
      return { ...state, number: state.number - 1 };
    case HomeTypes.HOME_SETNUMBER:
      return { ...state, number: action.number };
    case HomeTypes.HOME_RESET:
      return { ...state, number: 0 };
    default:
      return state;
  }
};
