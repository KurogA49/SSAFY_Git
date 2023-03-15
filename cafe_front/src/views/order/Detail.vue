<template>
  <div>

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
    this.$store.commit("SET_TITLE", "주문 상세");
    const result = await api.menus.findAll();
    console.log(result);
    this.menus = result.data;
  },
  methods: {
    setImage(image_src) {
      return `http://43.200.180.68:8080/${image_src}`;
    },
  },
}
</script>

<style scoped>

</style>