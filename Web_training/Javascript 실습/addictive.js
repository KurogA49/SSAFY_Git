const myName = "yang";

const introduce = "my name " + myName + " here";

const introduce2 = `my name ${myName} here`;

const hello = "HELLO!";


// insertAdjacentHTML 문자열로 된 html 태그를 집어넣기
const a = `
  <div class = "a">
    안녕하세요
  </div>
`;

const bb = () => `
  <div class = "a">
    ${hello}
  </div>
`;

document.querySelector('body').insertAdjacentHTML('beforeend', bb);

const run = (func1, func2) => func1(1, 2) * func2(3, 4);
const result = run(
    (a, b) => a + b,
    (a, b) => a * b
);
console.log(result);

