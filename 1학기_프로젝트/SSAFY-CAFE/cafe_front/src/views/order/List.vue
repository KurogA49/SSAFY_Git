<template>
  <div>
    <div class="order-header">주문 내역</div>
    <div class="order-body">
      <div class="order-list">
        <div class="order-menu" v-for="order in orders" :key="order.id">
          <div class="order-list-description">
            <div class="menu-name">주문번호 : {{ order.id }}</div>
            <div class="menu-detail order-name-font">품목 : {{ order.name }}</div>
            <div class="menu-detail order-quant-font">주문 수량 : {{ order.quantity }}</div>
            <div class="menu-detail order-req-font">요청 사항 : {{ order.request_detail }}</div>
          </div>
        </div>
      </div>
    </div>
  </div>
</template>

<script>
import { api } from "@/utils/axios";

export default {
  data() {
    return {
      orders: [],
    };
  },
  async created() {
    const result = await api.orders.findAll();
    console.log(result);
    this.orders = result.data;
  },
  methods: {
    setImage(image_src) {
      return `http://43.200.180.68:8080/${image_src}`;
    },
  },
};
</script>

<style>
.order-list-description {
  flex: 4;
  padding: 10px;
}
.order-name-font {
  color: purple;
  font-weight: bold;
}
.order-quant-font {
  color: cadetblue;
  font-weight: bold;
}
.order-req-font {
  color: cornflowerblue;
  font-weight: bold;
}
</style>