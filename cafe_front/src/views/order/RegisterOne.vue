<template>
  <div>
    <div class="menu-detail-body">
      <div class="a-menu">
        <div
          class="menu-detail-img"
          :style="`background-image:url(${setImage(data.image_src)})`"
        ></div>
        <div class="menu-detail-description">
          <h4>{{ data.name }}</h4>
          <div>{{ data.description }}</div>
        </div>
        <b-form-group class="order-request" label="요청사항">
          <b-form-input v-model="request" placeholder="입력"></b-form-input>
        </b-form-group>
        <div class="order-quantity">주문 갯수</div>
        <b-form-group class="menu-buttons">
          <div class="set-quantity">
            <b-button @click="lower">-</b-button>
            {{ quantity }}
            <b-button @click="upper">+</b-button>
            <b-button class="get-order" variant="success" @click="appendOrder"
              >주문 결정</b-button
            >
          </div>
        </b-form-group>
      </div>
    </div>
  </div>
</template>

<script>
import { api } from "@/utils/axios";
export default {
  data() {
    return {
      data: {},
      quantity: 1,
      request: "",
    };
  },
  async created() {
    this.$store.commit("SET_TITLE", "주문 상세");
    const result = await api.menus.findOne(this.$route.params.id);
    this.data = result.data;
  },

  methods: {
    setImage() {
      return `http://43.200.180.68:8080/${this.data.image_src}`;
    },
    upper() {
      this.quantity++;
    },
    lower() {
      if (this.quantity > 1) this.quantity--;
    },
    async appendOrder() {
      const req = await api.orders.create(
        this.data.id,
        this.quantity,
        this.request
      );
      this.$router.push(`/orders/register`);
    },
  },
};
</script>

<style>
.menu-detail-body {
  padding: 20px;
  display: flex;
  justify-content: center;
  align-items: center;
}
.a-menu {
  border: 1px solid black;
  width: 300px;
  height: 500px;
  display: flex;
  flex-direction: column;
  position: relative;
}
.menu-detail-img {
  flex: 4;
  width: 100%;
  height: 100%;
  background-size: cover;
  background-position: center;
}
.menu-detail-description {
  flex: 2;
  justify-content: center;
  text-align: center;
}
.menu-buttons {
  position: relative;
  flex: 1;
}
.set-quantity {
  position: absolute;
  width: 100%;
  bottom: 10px;
  left: 10px;
}
.get-order {
  position: absolute;
  right: 20px;
}
.order-request {
  padding: 10px;
  flex: 2;
}
.order-quantity {
  padding-left: 10px;
  padding-bottom: 10px;
}
</style>