<template>
  <div>
    <div v-if="loaded">
      <h1>Detail</h1>
      {{ menuId }}번 메뉴 상세 페이지입니다.
      <div class="menu-image" :style="`backgruond-image:url($(setImgae(this.data.image_src)))`"></div>
      <div>Menu : {{ data.name }}</div>
      <div>Detail : {{ data.description }}</div>
    </div>
    <div v-else>
      <b-spinner label="Spinning"></b-spinner>
    </div>
  </div>
</template>

<script>
import axios from "axios";

export default {
  data() {
    return {
      menuId: -1,
      data: [],
      loaded: false,
    };
  },
  async created() {
    this.menuId = this.$route.params.id;
    try {
      const response = await axios.get(
        `http://localhost:8080/api/menus/${this.menuId}`
      );
      this.data = response.data;
      this.loaded = true;
    } catch (error) {
      console.log(error);
    }
  },
  methods: {
    setImage(image_src) {
      return `http://localhost:8080/public/${image_src}`;
    }
  },
};
</script>

<style>
.menu-image {
  background-size: cover;
  background-position: center;
  width: 180px;
  height: 180px;
}
</style>