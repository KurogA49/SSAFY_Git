<template>
  <div>
    <h1>애비</h1>
    <div>{{ halbaeData2 }}</div>
    <button @click="changeHalbaeData">click!</button>
    <ParentChild
      :halbaeData="halbaeData"
      :halbaeData2="halbaeData2"
      :halbaeData3="halbaeData3"
      @changeHalbaeDataFromSonja="changeHalbaeDataFromSonja"
    />
  </div>
</template>

<script>
import ParentChild from "@/components/ParentChild.vue";
export default {
  components: {
    ParentChild,
  },
  props: ["halbaeData", "halbaeData2", "halbaeData3"],
  methods: {
    changeHalbaeData() {
      this.$emit("changeHalbaeData", "아들이 바꿨네");
    },
    changeHalbaeDataFromSonja(text) {
      this.$emit("changeHalbaeData", text);
    },
  },
};
</script>

<style>
</style>