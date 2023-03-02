const puppeteer = require("puppeteer");

const main = async() => {
  const browser = await puppeteer.launch({
    headless:false
  });
  const page = await browser.newPage();

  await page.goto("https://www.google.co.kr");

  await page.evaluate(() => {
    document.querySelector(".gLFyf").value = "치킨";
    document.querySelector(".gNO89b").click();
  })
  await page.waitForSelector(".GLcBOb");
  await page.screenshot({path:"chicken.jpg", fullPage:true});

  browser.close();
};

main();