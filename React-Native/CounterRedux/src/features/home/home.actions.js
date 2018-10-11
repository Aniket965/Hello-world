import HomeTypes from './home.types';

export const increment = () => ({
  type: HomeTypes.HOME_INCREMENT,
});

export const decrement = () => ({
  type: HomeTypes.HOME_DECREMENT,
});

export const setNumber = (number) => ({
  type: HomeTypes.HOME_SETNUMBER,
  number: number,
});

export const reset = data => ({
  type: HomeTypes.HOME_RESET,
});
