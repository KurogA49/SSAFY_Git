// const studentInfo = {
//   name: "Tony",
//   age: 31,
//   address: "Gwangju",
//   family: ["me", "wife", "cat"],
//   skill: {
//     client: ["vue.js", "vanilla", "react"],
//     server: ["django", "php", "node.js"],
//     db: ["sqlite", "mongo", "mysql", "postgresql"],
//   },
//   sayHi: () => console.log("hi"),
// };

// const studentInfo = new Object();

// studentInfo.name = "Tony";
// studentInfo.age = 31;
// studentInfo.addrss = "Gwangju";
// studentInfo.family = ["me", "wife", "cat"];
// studentInfo.skill = {
//   client: ["vue.js", "vanilla", "react"],
//   server: ["django", "php", "node.js"],
//   db : ["sqlite", "mongo", "mysql", "postgressql"],
// };
// studentInfo.sayHi = () => console.log("Hi");

// studentInfo = {
//   name: String,
//   age: Number,
//   address : String,
//   family: Array,
//   skill: Object,
//   sayHi: Function,
// };

// const student1 = new studentInfo();
// student1.name = "Tony";
// student1.age = 31;

// class StudentInfo {
//   constructor(name, age) {
//     this.name = name;
//     this.age = age;
//     this.address = "";
//   }
//   sayMyName() {
//     console.log(`my name is ${this.name}`);
//   }
//   setAddress(address) {
//     this.address = address;
//   }
//   getAddress() {
//     return this.address;
//   }
//   useMethod() {
//     this.sayMyName();
//   }
// }

// const student1 = new StudentInfo("jony", 30);
// student1.sayMyName();
// student1.setAddress("경기 군포시 산본동");
// console.log(student1.getAddress());
// student1.useMethod();

const student1 = {
  name: "",
  age: -1,
  address: "",
  constructor: function(name, age) {
    this.name = name;
    this.age = age;
    this.address = "";
  },
  sayMyName: () => {
    console.log(`my name is ${this.name}`);
  },
  setAddress: (address) => (this.address = address),
  getAddress: () => this.address,
  usedMethod: () => {
    this.sayMyName();
  },
};

student1.constructor("jony", 30);
student1.sayMyName();
student1.setAddress("경기 군포시 산본동");
console.log(student1.getAddress());

class Lawyer {
  constructor(name, age, intro) {
    this.name = name;
    this.age = age;
    this.introduction = intro;
  }

  introduce() {
    console.log(`이름 : ${this.name}`);
    console.log(`나이 : ${this.age}`);
    console.log(`자기소개 : ${this.introduction}`);
  }
}

const woo = new Lawyer("우영우", 27, "기러기 토마토 스위스 역삼역");
const choi = new Lawyer("최수연", 27, "봄날의 햇살");

class Hero {
  constructor(hp) {
    this.hp = hp;
  }
  showHP() {
    console.log(this.hp);
  }
  run() {
    this.hp -= 10;
  }
}

class SuperMan extends Hero {
  fly() {
    this.run();
    this.run();
  }
}

class Person {
  constructor(name, hp) {
    this.name = name;
    this.hp = hp;
  }
  hello() {
    console(`My name is ${this.name}`);
  }
}

class Avengers extends Person {
  constructor(name, hp, power, skill) {
    this.name = name;
    this.hp = hp;
    this.power = power;
    this.skill = skill;
  }
  information() {
    this.hello();
  }
}

const batman = new Hero(100);
batman.showHP();
batman.run();
batman.run();
batman.showHP();

const sm = new SuperMan(100);
sm.showHP();
sm.fly();
sm.fly();
sm.showHP();

