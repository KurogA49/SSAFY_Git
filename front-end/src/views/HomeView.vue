<template>
  <div>
    <h1>Home</h1>
    <ul v-if="menus.length">
      <li v-for="menu in menus" :key="menu.id">
        <div class="menu-name" @click="goDetail(menu.id)">
          <h6>{{ menu.name }}</h6>
        </div>
        <hr />
      </li>
    </ul>
    <div v-else>
      <b-spinner label="Spinning"></b-spinner>
      <div>NOW LOADING...</div>
    </div>
  </div>
</template>

<script>
import axios from "axios";

export default {
  data() {
    return {
      menus: [],
    };
  },
  async created() {
    try {
      const response = await axios.get("http://localhost:8080/api/menus");
      this.menus = response.data;
    } catch (error) {
      console.log(error);
    }
  },
  methods: {
    goDetail(id) {
      this.$router.push(`/detail/${id}`);
    },
  },
};
</script>

<style scoped>
.menu-name {
  color: blue;
}
</style>
