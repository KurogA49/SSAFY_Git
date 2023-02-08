const person = {
  name: "이자룡",
  familyMembers: ["아빠", "엄마", "할머니"],
  job: "싸피 강사",
  isMerriaged: true,
  codingSkill: {
    frontend: ["vue.js", "react.js", "vanillaJS"],
    backend: ["node.js", "php", "django"],
    database: ["mariadb", "postgresql", "mysql", "sqlite"],
  },
};

console.log(person.name);
console.log(person.familyMembers[2]);
console.log(person.codingSkill.frontend[1]);
console.log(person.codingSkill.frontend);