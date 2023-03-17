const express = require("express");
const app = express();
const PORT = 8081;

const cors = require("cors");
app.use(cors());

const morgan = require("morgan");
app.use(morgan("dev"));

const axios = require("axios");
const dotenv = require("dotenv");
const fs = require("fs");
dotenv.config();

app.use(express.json());

app.get("/", async (req, res) => {
  try {
    return res.json({
      test: true,
    });
  } catch (error) {
    console.log(error);
    return res.json({
      test: false,
    });
  }
});

app.get("/data", async (req, res) => {
  try {
    // 기본적으로 Naver 서버가 아닌 back-end에 저장된 chart.json 파일을 반환하는 것
    res.set("Content-Type", "application/json; charset=utf-8");
    const tempFile = fs.createReadStream("uploads/chart.json");
    // tempFile은 readable stream이고 res는 응답 객체이므로 이 둘을 연결하기 위해 pipe() 를 사용
    return tempFile.pipe(res);
  } catch (error) {
    return res.json(error);
  }
});

app.post("/data", async (req, res) => {
  const { startDate, endDate, timeUnit, device, gender, keywordGroups } =
    req.body;
  try {
    const request_body = {
      startDate: startDate,
      endDate: endDate,
      timeUnit: timeUnit,
      device: device === "all" ? "" : device,
      gender: gender === "all" ? "" : gender,
      keywordGroups: keywordGroups,
    }
    // 전송할 서버 주소와 접속 설정 헤더
    // client-id 및 client-secret은 개인 정보이므로
    // 별도의 .env 파일을 통해 간접 참조하여 보안성 유지
    const url = "https://openapi.naver.com/v1/datalab/search";
    const headers = {
      "Content-type": "application/json",
      "X-Naver-Client-Id": process.env.CLIENT_ID,
      "X-Naver-Client-Secret": process.env.CLIENT_SECRET,
    };
    // 실제 비동기 axios 통신
    const response = await axios.post(url, request_body, {
      headers: headers,
    });

    // 통신 응답을 파일로 변환
    fs.writeFile(
      "./uploads/chart.json",
      JSON.stringify(response.data.results),
      (error) => {
        if (error) {
          throw error;
        }
      }
    );
    console.log(response.data);
    // 통신이 잘 이루어졌는지 확인하기 위해 통신 응답을 json으로 출력
    return res.json(response.data.results);
  } catch (error) {
    return res.json(error);
  }
});

app.delete("/data", (req, res) => {
  try {
    fs.unlink("uploads/chart.json", (error) => {
      if (error) return res.json(error);
    });
    return res.json({
      delete: true,
    });
  } catch (error) {
    return res.json(error);
  }
});

app.listen(PORT, () => console.log(`this server listening on ${PORT}`));
