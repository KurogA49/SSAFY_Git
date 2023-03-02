const puppeteer = require("puppeteer");

const main = async() => {
  const browser = await puppeteer.launch({
    headless:false
  });
  const page = await browser.newPage();

  await page.goto("https://news.daum.net/digital#1");

  const data = await page.evaluate(() => {
    const newsList = document.querySelectorAll(".list_newsmajor > li .link_txt");
    const result = Array.from(newsList).map(li => li.textContent);
    return result;
  });

  console.log(data);

  browser.close();
}

main();