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

// const studnets = [
//   {
//     name: "tony",
//     age: 31,
//     address: "Gwangju",
//   },
//   {
//     name: "penny",
//     age: 28,
//     address: "Naju",
//   },
//   {
//     name: "paul",
//     age: 25,
//     address: "Hwasun",
//   },
// ];

// function samplefunc(std) {
//   return std.age < 30;
// }

// const uneder30peoples = studnets.filter(samplefunc);

// const under30names = uneder30peoples.map((std) => std.name);

// console.log(under30names);

// const arr1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

// const result1 = arr1.filter((val) => val % 2 === 0);
// const result1_10 = result1.map((val) => val * 10);
// console.log(result1_10);

// const orderList = [
//   {
//     name: "치킨",
//     price: 13000,
//     event: false,
//     count: 50,
//   },
//   {
//     name: "돈까스",
//     price: 8500,
//     event: true,
//     count: 99,
//   },
//   {
//     name: "마라탕",
//     price: 8000,
//     event: false,
//     count: 100,
//   },
//   {
//     name: "쫄면",
//     price: 6500,
//     event: false,
//     count: 0,
//   },
//   {
//     name: "짜장면",
//     price: 5500,
//     event: true,
//     count: 30,
//   },
// ];

// const filteredMenu = orderList
//   .filter((menu) => menu.count > 0)
//   .map((menu) => {
//     const newOrder = structuredClone(menu);
//     if (menu.event) {
//       newOrder.saledPrice = newOrder.price * 0.9;
//       return newOrder;
//     }
//     newOrder.saledPrice = newOrder.price;
//     return newOrder;
//   });

// console.log(filteredMenu);

// const dataFromServer = [
//   {
//     name: "jony",
//     age: "30",
//   },
//   {
//     name: "kevin",
//     age: "26",
//   },
//   {
//     name: "pipi",
//     age: "4",
//   },
// ];

// if (dataFromServer) {
//   console.log("있다");
// } else {
//   console.log("없다");
// }

// const abc = {
//   name : "chicken",
//   typeOfMenu : "fried",
// };

// const {name, typeOfMenu} = abc;
// console.log(name);
// console.log(typeof typeOfMenu);

// const sampleFunc = () => {
//   return [1, 2];
// }

// const [one, two] = sampleFunc();

// console.log(one);
// console.log(two);

// const square = {
//   width: 200,
//   height: 200,
// }
// const colorSquare = {
//   width: square.width,
//   height: square.height,
//   color: "red",
// };

// const chicken = {
//   type: "source",
//   drumsticks: 2,
//   wing: 2,
// };

// const {type, ...another} = chicken;
// console.log(another);

// const bucketLists = [
//   { id: 3, text: "여행가기", done: false, },
//   { id: 2, text: "치킨 먹기", done: true, },
//   { id: 1, text: "코딩 하기", done: false, },
// ];

// const getValues = (key) =>
//   bucketLists.map((bucketList) => bucketList[key]);

// console.log(getValues('id'));
// console.log(getValues('text'));
// console.log(getValues('done'));

// const filtering = (key, value) =>
//   bucketLists.filter(item => item[key] !== value);

// const toggle = (id) => {
//   const newBucketLists = structuredClone(bucketLists);
//   const ret = newBucketLists.filter((item) => item.id === id);
//   if(ret[0].done) {
//     ret[0].done = false;
//   } else {
//     ret[0].done = true;
//   }
//   return newBucketLists;
// };

// console.log(toggle(1));

const studentInfo =  [
  {
    name : "tony",
    age : 30,
  },
  {
    name : "paul",
    age : 24,
  },
  {
    name : "pipi",
    age : 18,
  },
];

