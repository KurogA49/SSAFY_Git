<template>
  <div>
    <h1>할배</h1>
    {{ halbaeData }}
    <HomeParent
      :halbaeData="halbaeData"
      :halbaeData2="halbaeData2"
      :halbaeData3="halbaeData3"
      @changeHalbaeData="changeHalbaeData"
    />
  </div>
</template>

<script>
import HomeParent from "@/components/HomeParent.vue";
export default {
  components: {
    HomeParent,
  },
  data() {
    return {
      halbaeData: "나는 꽃보다 할배",
      halbaeData2: "나는 터미네이터 할배",
      halbaeData3: "나는 무림고수 할배",
    };
  },
  methods: {
    changeHalbaeData(text) {
      this.halbaeData = text;
    },
  },
};
</script>

<style>
</style>