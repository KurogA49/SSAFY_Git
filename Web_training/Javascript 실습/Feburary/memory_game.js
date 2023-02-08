const cardSet = [
  {
    name: "cat",
    img: "./public/cat.png",
    id: "",
    done: false,
  },
  {
    name: "cat",
    img: "./public/cat.png",
    id: "",
    done: false,
  },
  {
    name: "dog",
    img: "./public/dog.png",
    id: "",
    done: false,
  },
  {
    name: "dog",
    img: "./public/dog.png",
    id: "",
    done: false,
  },
  {
    name: "elephant",
    img: "./public/elephant.png",
    id: "",
    done: false,
  },
  {
    name: "elephant",
    img: "./public/elephant.png",
    id: "",
    done: false,
  },
  {
    name: "hedgehog",
    img: "./public/hedgehog.png",
    id: "",
    done: false,
  },
  {
    name: "hedgehog",
    img: "./public/hedgehog.png",
    id: "",
    done: false,
  },
  {
    name: "pig",
    img: "./public/pig.png",
    id: "",
    done: false,
  },
  {
    name: "pig",
    img: "./public/pig.png",
    id: "",
    done: false,
  },
  {
    name: "squirrel",
    img: "./public/squirrel.png",
    id: "",
    done: false,
  },
  {
    name: "squirrel",
    img: "./public/squirrel.png",
    id: "",
    done: false,
  },
];

let clickcount = 0;
let clickfirst = -1;
let clicksecond = -1;

// ----------- 데이터 파트 ----------

const setClickHistory = (location) => {
  if (clickfirst === -1) {
    clickfirst = location;
  } else {
    clicksecond = location;
  }
};

const backFlip = () => {
  const parseIdFirst = cardSet[clickfirst].id.split("-");
  const parseIdSecond = cardSet[clicksecond].id.split("-");
  setTimeout(() => {
    gameDOM[parseIdFirst[0]][parseIdFirst[1]].querySelector("img").src =
      "./public/Question-Mark.png";
    gameDOM[parseIdSecond[0]][parseIdSecond[1]].querySelector("img").src =
      "./public/Question-Mark.png";
  }, 500);
};

const isCorrect = () => {
  if (cardSet[clickfirst].name === cardSet[clicksecond].name) {
    cardSet[clickfirst].done = true;
    cardSet[clicksecond].done = true;
  } else {
    backFlip();
  }
};

const flip = (location) => {
  if (!cardSet[location].done) {
    setClickHistory(location);

    const parseId = cardSet[location].id.split("-");
    gameDOM[parseId[0]][parseId[1]].querySelector("img").src =
      cardSet[location].img;

    clickcount++;
    if (clickcount === 2) {
      clickcount = 0;
      isCorrect();
    }
    if (clickfirst !== -1 && clicksecond !== -1) {
      clickfirst = -1;
      clicksecond = -1;
    }
  }
};

const gameDOM = [];

const getGameDOM = () => {
  const rows = document.querySelectorAll(".row");
  rows.forEach((row, idx) => {
    gameDOM[idx] = row.querySelectorAll(".column");
  });
  console.log(gameDOM);
};

const setIDtoCardSet = () => {
  cardSet[0].id = "0-0";
  cardSet[1].id = "0-1";
  cardSet[2].id = "0-2";
  cardSet[3].id = "0-3";
  cardSet[4].id = "1-0";
  cardSet[5].id = "1-1";
  cardSet[6].id = "1-2";
  cardSet[7].id = "1-3";
  cardSet[8].id = "2-0";
  cardSet[9].id = "2-1";
  cardSet[10].id = "2-2";
  cardSet[11].id = "2-3";
};

const createBoard = () => {
  for (let i = 0; i < gameDOM.length; i++) {
    for (let j = 0; j < gameDOM[i].length; j++) {
      const card = document.createElement("img");
      card.setAttribute("src", "./public/Question-Mark.png");
      card.classList.add("eachImgae");
      gameDOM[i][j].appendChild(card);
    }
  }
};

// ----------- 함수 정의 파트 ----------

getGameDOM();
cardSet.sort(() => 0.5 - Math.random());
setIDtoCardSet();
createBoard();

// ----------- 함수 실행 파트 ----------
