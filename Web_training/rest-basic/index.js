const express = require("express");
const app = express();
const PORT = 8080;

app.use(express.json());

const cors = require("cors");
app.use(cors());

const { pool } = require("./db");
const morgan = require("morgan");

app.use(morgan("dev"));

// Menus part
// get all
app.get("/api/menus", async (req, res) => {
  try {
    const data = await pool.query(`SELECT * FROM menus`);
    if (data[0]) {
      return res.json(data[0]);
    }
  } catch (error) {
    return res.json({
      success: false,
      message: "전체 메뉴 목록 조회에 실패하였습니다.",
    });
    console.log(error);
  }
});
// get an item
app.get("/api/menus/:id", async (req, res) => {
  try {
    const data = await pool.query(
      `
      SELECT * FROM menus WHERE id = ${req.params.id}
    `
    );
    if (!data[0].length)
      return res.json({
        success: false,
        message: "아이디에 해당하는 값이 존재하지 않습니다.",
      });
    else return res.json(data[0][0]);
  } catch (error) {
    console.log(error);
  }
});
// post an item
app.post("/api/menus", async (req, res) => {
  try {
    const data = await pool.query(
      `
      INSERT INTO menus
      (name, description, image_src)
      VALUES
      ("${req.body.name}", "${req.body.description}", "${req.body.image_src}")
    `
    );
    if (data[0].affectedRows) {
      const result = await pool.query(
        "SELECT * FROM menus ORDER BY id DESC LIMIT 1"
      );
      return res.json(result[0][0]);
    }
  } catch (error) {
    return res.json({ success: false, message: "메뉴 등록에 실패하였습니다." });
    console.log(error);
  }
});
// patch an item
app.patch("/api/menus/:id", async (req, res) => {
  try {
    const data = await pool.query(
      `
      UPDATE menus
      SET name = "${req.body.name}", description = "${req.body.description}", image_src = "${req.body.image_src}"
      WHERE id = ${req.params.id}
    `
    );
    if (data[0].affectedRows) {
      const result = await pool.query(
        `SELECT * FROM menus WHERE id = ${req.params.id}`
      );
      return res.json(result[0][0]);
    } else {
      return res.json({ success: false, message: "존재하지 않는 메뉴입니다." });
    }
  } catch (error) {
    return res.json({ success: false, message: "잘못된 요청입니다." });
    console.log(error);
  }
});
// delete an item
app.delete("/api/menus/:id", async (req, res) => {
  try {
    const data = await pool.query(
      `
      DELETE FROM menus WHERE id = ${req.params.id}
    `
    );
    if (data[0]) return res.json(data[0]);
  } catch (error) {
    console.log(error);
  }
});


// Orders part
// get all
app.get("/api/orders", async (req, res) => {
  try {
    const data = await pool.query(
      `
      SELECT orders.id, menus.name, orders.quantity, orders.request_detail
      FROM orders
      INNER JOIN menus
      ON orders.menus_id = menus.id
      `
    );
    if (data[0]) return res.json(data[0]);
  } catch (error) {
    return res.json({
      success: false,
      message: "전체 주문 목록 조회에 실패하였습니다.",
    });
    console.log(error);
  }
});

// get an order
app.get("/api/orders/:id", async (req, res) => {
  try {
    const data = await pool.query(
      `
      SELECT orders.id, menus.name,  orders.quantity,  orders.request_detail
      FROM  orders
      INNER JOIN menus
      ON  orders.menus_id =  menus.id
      WHERE orders.id = ${req.params.id};
    `
    );
    if (!data[0].length)
      return res.json({
        success: false,
        message: "해당 주문이 존재하지 않습니다.",
      });
    else return res.json(data[0][0]);
  } catch (error) {
    console.log(error);
  }
});

// post an order
app.post("/api/orders", async (req, res) => {
  try {
    const data = await pool.query(
      `
      INSERT INTO orders
      (quantity, request_detail, menus_id)
      VALUES
      ("${req.body.quantity}", "${req.body.request_detail}", "${req.body.menus_id}")
    `
    );
    if (data[0].affectedRows) {
      const result = await pool.query(
        "SELECT * FROM orders ORDER BY id DESC LIMIT 1"
      );
      return res.json(result[0][0]);
    }
  } catch (error) {
    return res.json({ success: false, message: "주문에 실패하였습니다." });
    console.log(error);
  }
});

// patch an order
app.patch("/api/orders/:id", async (req, res) => {
  try {
    const data = await pool.query(
      `
      UPDATE orders
      SET quantity = "${req.body.quantity}",
      request_detail = "${req.body.request_detail}",
      menus_id = "${req.body.menus_id}"
      WHERE id = ${req.params.id}
    `
    );
    if (data[0].affectedRows) {
      const result = await pool.query(
        `SELECT * FROM orders WHERE id = ${req.params.id}`
      );
      return res.json(result[0][0]);
    } else {
      return res.json({ success: false, message: "존재하지 않는 주문입니다." });
    }
  } catch (error) {
    return res.json({ success: false, message: "잘못된 주문입니다." });
    console.log(error);
  }
});

// delete an order
app.delete("/api/orders/:id", async (req, res) => {
  try {
    const data = await pool.query(
      `
      DELETE orders FROM orders WHERE id = ${req.params.id}
    `
    );
    if (data[0]) return res.json(data[0]);
  } catch (error) {
    console.log(error);
  }
});

app.listen(PORT, () => console.log(`this server is listening on ${PORT}`));
