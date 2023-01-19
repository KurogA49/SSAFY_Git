// toggle button
const toggleButton = document.querySelector(".toggle-button");
// background
const bodyBackground = document.querySelector("body");
// header-nav
const headerNav = document.querySelector(".header-nav-list-wrapper");
// bookmark-wrapper
const bookmarkWrapper = document.querySelector(".bookmark-wrapper");
// search-input
const searchInput = document.querySelector("#search-input");
// image-icon-wrapper
const imgIconWrappers = document.querySelectorAll(".img-icon-wrapper");
// bookmark-text
const bookmarkTexts = document.querySelectorAll(".bookmark-text");
// bookmark-item
const bookmarkItems = document.querySelectorAll(".bookmark-item");

toggleButton.addEventListener("click", () => {
  // click
  // the text must be changed from default => dark mode
  toggleButton.textContent = "다크 모드";

  toggleButton.classList.toggle("toggle-button-darkmode");
  bodyBackground.classList.toggle("body-background-darkmode");
  headerNav.classList.toggle("text-darkmode");

  for(let i = 0; i < imgIconWrappers.length; i++) {
    imgIconWrappers[i].classList.toggle("img-icon-wrapper-darkmode");
  }
  for(let i = 0; i < bookmarkTexts.length; i++) {
    bookmarkTexts[i].classList.toggle("text-darkmode");
  }
  if (toggleButton.classList.contains("toggle-button-darkmode"))
    toggleButton.textContent = "일반 모드";
});


searchInput.addEventListener('keyup', (e) => {
  // e.code 를 통해 어떤 키를 입력했는지 알 수 있다.
  // enter를 입력했을 때 바로 검색화면으로 이동할 수 있게
  if(e.code === "Enter") {
    // 검색어가 존재할 경우만
    if(!e.target.value) {
      alert("검색어를 입력하지 않았습니다.");
      return;
    }
    // 이동하기
    const googleSearch = "https://www.google.com/search?q=";
    // location.href = googleSearch + e.target.value;
    // 새창으로 열기
    // window.open
  window.open(googleSearch + e.target.value, "_blank");
  }
})