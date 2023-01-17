function addOne(n) {
  return n + 1;
}

function numToString(n) {
  return String(n);
}

function StringToNum(text) {
  return Number(text);
}

function sampleFunc() {
  return 1;
}

const functionA = sampleFunc();
const functionB = sampleFunc;

console.log(functionA);
console.log(functionB);

const a = numToString(2);
const b = StringToNum("2");
console.log(typeof a);
console.log(typeof b);

const person = {
  name: "Panny Kim",
  dateOfBirth: 1993,
  familyMembers: ["father", "mother", "grandma"],
  job: "instructor",
  isMarriaged: true,
};

const sta = "ABC" + "DEF";
console.log(sta);

console.log(1 == "1");
console.log(1 === "1");

const arr = [1, 2, 3, 1, 2, 3, 1, 2, 3];
let count = 0;
for(let i = 0; i < arr.length; i++) {
  if(arr[i] == 1) {
    count++;
  }
}
console.log(count);

let chCount = 0;
const chArr = ['A', 'E', 'W', 'Q', 'A'];
for(let i = 0; i < chArr.length; i++) {
  if(chArr[i] == "A") {
    chCount++;
  }
}
if(chCount > 0) {
  console.log("O");
} else {
  console.log("X");
}