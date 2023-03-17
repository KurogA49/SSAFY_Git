<template>
  <div>
    <h1>아들</h1>
    {{ halbaeData3 }}
    <div>
      <input type="text" v-model="inputData"/>
      <button @click="changeHalbaeDataFromSonja">click this!</button>
    </div>
  </div>
</template>

<script>
export default {
  data() {
    return {
      inputData: "",
    }
  },
  props: ["halbaeData", "halbaeData2", "halbaeData3"],
  methods: {
    changeHalbaeDataFromSonja() {
      this.$emit("changeHalbaeDataFromSonja", this.inputData);
    },
  },
};
</script>

<style>
</style>