const nums = [1, 2, 3, 4];

// map : 기존 배열의 원소마다 함수를 호출하여 그 결과를 새 배열에 저장
const tmp = nums.map((num) => {
  return num + 5;
});
tmp;

// filter : 기존 배열의 원소를 함수 내 조건에 만족하는 경우만 새 배열에 저장
const tmp2 = nums.filter((num) => {
  return num % 2 === 0;
});
tmp2;

// find : 기존 배열의 원소와 찾고자 하는 값을 반환하고 중복될 경우 처음 값만 반환
const tmp3 = nums.find((num) =>{
  return num === 3;
})
tmp3;

// every : 기존 배열의 모든 원소들이 주어진 함수 내 조건을 만족한다면 true,
// 하나라도 틀리면 false
const tmp4 = nums.every((num) => {
  return num > 2;
})
tmp4;
const tmp5 = nums.every((num) => {
  return num > 0;
})
tmp5;

// some : 기존 배열의 어떤 원소라도 주어진 함수 내 조건을 만족한다면 true,
// 전부 틀리면 false;
const tmp6 = nums.some((num) => {
  return num > 3;
})
tmp6;
const tmp7 = nums.some((num) => {
  return num > 4;
})
tmp7;

// reduce : 기존 배열의 원소를 누산하여 지정된 변수에 저장
const tmp8 = nums.reduce((tmp8, num) => tmp8 + num, 0)
tmp8;