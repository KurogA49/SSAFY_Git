// const array = [1, 2, 3, 4, 5, 6];
// const result = array.map(data => {return data});

// const arr = [1, 2, 3, 4, 5];
// const result = arr.map(val => {return val * val});
// console.log(result);

// const arr2 = ["a", "bcd", "ef", "g"];
// const result2 = arr2.map(val => {return val.length});
// console.log(result2)

// filter
// const array = [3, 5, 4, 2];
// const filtered = array.filter(data => data > 3);
// console.log(filtered);

// const bucketList = [
//   {
//     id: 1,
//     text: "여행 가기",
//     done: false,
//   },
//   {
//     id: 2,
//     text: "치킨 먹기",
//     done: true,
//   },
//   {
//     id: 3,
//     text: "코딩 하기",
//     done: true,
//   },
//   {
//     id: 4,
//     text: "요리하기",
//     done: false,
//   },
// ];

// const notyet = bucketList.filter((obj) => obj.done === false);
// console.log(notyet);

const studnets = [
  {
    name: "tony",
    age: 31,
    address: "Gwangju",
  },
  {
    name: "penny",
    age: 28,
    address: "Naju",
  },
  {
    name: "paul",
    age: 25,
    address: "Hwasun",
  },
];

function samplefunc(std) {
  return std.age < 30;
}

const uneder30peoples = studnets.filter(samplefunc);

const under30names = uneder30peoples.map((std) => std.name);

console.log(under30names);

const arr1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

const result1 = arr1.filter((val) => val % 2 === 0);
const result1_10 = result1.map((val) => val * 10);
console.log(result1_10);

const orderList = [
  {
    name: "치킨",
    price: 13000,
    event: false,
    count: 50,
  },
  {
    name: "돈까스",
    price: 8500,
    event: true,
    count: 99,
  },
  {
    name: "마라탕",
    price: 8000,
    event: false,
    count: 100,
  },
  {
    name: "쫄면",
    price: 6500,
    event: false,
    count: 0,
  },
  {
    name: "짜장면",
    price: 5500,
    event: true,
    count: 30,
  },
];

const filteredMenu = orderList.filter(menu => menu.count > 0);
const saledMenu = filteredMenu.map(menu => {
  if(menu.event)
    menu.saledprice = menu.price - menu.price * 0.1;
  return menu;
})
console.log(saledMenu);