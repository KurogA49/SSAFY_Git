// 배열 메소드 Array.함수(콜백함수)
// addEventListener('click', function() { })

// Array.forEach
// const arr = [4, 3, 5, 1, 6, 5];
// let cnt = 0;

// arr.forEach((val) => {
//   if(val % 2 == 1)
//     cnt++;
// })
// console.log(cnt);

// Array.push
// const arr = [-5, 3, 4, 2, -7, -2, 7];
// const pplus = [];
// const mminus = [];

// arr.forEach((val) => {
//   if(val > 0)
//     pplus.push(val);
//   else
//     mminus.push(val);
// })

// console.log(pplus);
// console.log(mminus);

// Array.some
// const array = [1, 2, 3, 4, 5];
// const result1 = array.some(element => element < 0);
// const result = array.some(element => element > 4);

// Array.every
// const result3 = array.every(element => element > 0);
// const result4 = array.every(element => element > 2);

// Array.find
// const array = [1, 2, 3, 4, 5];
// const inventory = [
//   { name: "A", quantity: 1 },
//   { name: "B", quantity: 2 },
//   { name: "C", quantity: 3 },
// ];

// const result1 = array.find(element => element > 2);
// console.log(result1);
// const result2 = inventory.find(li => li.name === "B");
// console.log(result2);

//Array.findIndex
// const result3 = array.findIndex(element => element > 2);
// console.log(result3);
// const result4 = inventory.findIndex(li => li.name === "B");
// console.log(result4);

// const chicken = [
//   {name: "머리", quantity: 1},
//   {name: "날개", quantity: 2},
//   {name: "닭다리", quantity: 2},
//   {name: "닭가슴살", quantity: 1},
//   {name: "닭발", quantity: 2},
// ];

// const leg = chicken.find(li => li.name === "닭다리");
// console.log(leg);
// const legidx = chicken.findIndex(li => li.name === "닭다리");
// console.log(legidx);