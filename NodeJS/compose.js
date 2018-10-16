//compose :: (Function -> Function) -> * a -> a
const compose = (f, g) => {
  return x => {
    return f(g(x));
  };
};

const add1 = x => x + 1;
const add2 = compose(
  add1,
  add1
);

add2(2); //4
