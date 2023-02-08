const movielist = document.querySelectorAll(
  "#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li"
);

const firstboxcontents = movielist[0].querySelector("div.box-contents");
const firstmoviename = firstboxcontents.querySelector("strong.title");
const firstmoviepercent = firstboxcontents.querySelector("strong.percent > span");
const firstmovieday = firstboxcontents.querySelector("span.txt-info > strong");
const firstmovieimage = movielist[0].querySelector("div.box-image > a > span.thumb-image > img");

const secondboxcontents = movielist[1].querySelector("div.box-contents");
const secondmoviename = secondboxcontents.querySelector("strong.title");
const secondmoviepercent = secondboxcontents.querySelector("strong.percent > span");
const secondmovieday = secondboxcontents.querySelector("span.txt-info > strong");
const secondmovieimage = movielist[1].querySelector("div.box-image > a > span.thumb-image > img");

const thirdboxcontents = movielist[2].querySelector("div.box-contents");
const thirdmoviename = thirdboxcontents.querySelector("strong.title");
const thirdmoviepercent = thirdboxcontents.querySelector("strong.percent > span");
const thirdmovieday = thirdboxcontents.querySelector("span.txt-info > strong");
const thirdmovieimage = movielist[2].querySelector("div.box-image > a > span.thumb-image > img");

secondmoviename.textContent = "삼겹살과 그대라면";
secondmoviepercent.textContent = "5%";
secondmovieday.textContent = "1985.07.07 개봉";



const boxContents = document.querySelectorAll(".box-contents");
const boxImages = document.querySelectorAll("div.box-image");

const movie1name = boxContents[0].querySelector("strong.title");
const movie1percent = boxContents[0].querySelector("strong.percent > span");
const movie1day = boxContents[0].querySelector("span.txt-info >strong");
const movie1image = boxImages[0].querySelector(".thumb-image > img");

const movie2name = boxContents[1].querySelector("strong.title");
const movie2percent = boxContents[1].querySelector("strong.percent > span");
const movie2day = boxContents[1].querySelector("span.txt-info >strong");
const movie2image = boxImages[1].querySelector(".thumb-image > img");

const movie3name = boxContents[2].querySelector("strong.title");
const movie3percent = boxContents[2].querySelector("strong.percent > span");
const movie3day = boxContents[2].querySelector("span.txt-info >strong");
const movie3image = boxImages[2].querySelector(".thumb-image > img");

let tmp = movie1name.textContent;
movie1name.textContent = movie3name.textContent;
movie3name.textContent = tmp;