<template>
  <div>
    <div class="order-body">
      <div class="order-list" v-if="menus.length">
        <div class="order-menu" v-for="menu in menus" :key="menu.id">
          <div
            class="menu-img"
            :style="`background-image:url(${setImage(menu.image_src)})`"
          ></div>
          <div class="menu-description">
            <div class="menu-name">{{ menu.name }}</div>
            <div class="menu-detail">{{ menu.description }}</div>
          </div>
          
          <b-button @click="moveOrderDetail(menu.id)">주문하기</b-button>
        </div>
      </div>
      <div v-else>
        <b-spinner class="loading-spinner" label="Spinning"></b-spinner>
      </div>
    </div>
  </div>
</template>

<script>
import { api } from "@/utils/axios";

export default {
  data() {
    return {
      menus: [],
    };
  },
  async created() {
    this.$store.commit("SET_TITLE", "주문하기");
    const result = await api.menus.findAll();
    console.log(result);
    this.menus = result.data;
  },
  methods: {
    setImage(image_src) {
      return `http://43.200.180.68:8080/${image_src}`;
    },
    moveOrderDetail(id) {
      this.$router.push(`/orders/register/${id}`);
    }
  },
};
</script>

<style>
.order-header {
  font-size: 30px;
  font-weight: bold;
  text-align: center;
  border-bottom: 1px solid black;
}
.loading-spinner {
  flex: 1;
}
.order-body {
  display: flex;
  justify-content: center;
  align-items: center;
  flex-direction: row;
}
.order-menu {
  padding: 10px;
  margin: 10px;
  width: 95%;
  height: 90%;
  border: 1px solid black;
  display: flex;
  align-items: center;
}
.menu-img {
  flex: 1;
  padding: 10px;
  background-size: cover;
  background-position: center;
  width: 80px;
  height: 80px;
}
.menu-description {
  flex: 4;
  padding: 10px;
}
</style>