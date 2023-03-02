// 패키지 import
// require

const puppeteer = require("puppeteer");

const main = async() => {
  // 브라우저를 만들기
  const browser = await puppeteer.launch({
    // 기본값이 headless:true
    headless:false
  })
  // 브라우저의 페이지 만들기
  const page = await browser.newPage();
  // 페이지에서 주소로 이동하기
  await page.goto("https://comic.naver.com/webtoon?tab=mon");

  // 대기하는 법
  // waitForSelector -> 특정 selector가 올 때까지 대기하는 역할
  // 이미지가 로딩 시에 없었으니 이를 기다리는 메소드

  // document.querySelectorAll("#content .item");
  await page.waitForSelector("#content .item img");

  // 스크랩 데이터 가져오기
  // node.js는 브라우저가 아닌 런타임이므로 document 사용 불가능
  // 단, evaluate 안에서는 document 사용이 가능
  // headless : false
  const data = await page.evaluate(() => {
    const webtoonList = document.querySelectorAll("#content .item img");
    
    // querySelectorAll은 유사 배열이므로
    // -> Array.from으로 배열화를 시킨 후에 배열 메서드 사용
    const result = Array.from(webtoonList).map(li => li.getAttribute('alt'));
    return result;
  });
  console.log(data);

  // 스크린샷
  // await page.screenshot({path: "screenshot.jpg", fullPage:true});
  // pdf 스크랩 (headless : true 에서만 동작)
  // await page.pdf({path: "test.pdf", format:'A4'});
  // 브라우저 종료
  // await browser.close();
}

main();