const names =  ["tony", "paul", "pipi"];

// slice
// const newNames = names.slice(1);
// console.log(newNames);
// console.log(names);

//splice
const newNames = names.splice(1, 3);
console.log(names);
console.log(newNames);

function cutName(name) {
  const idx = names.indexOf(name);
  const before = names.splice(idx);
}