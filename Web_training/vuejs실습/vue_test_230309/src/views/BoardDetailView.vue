<template>
  <div>
    <h1>Detail</h1>
    <div>This is {{ id }}'s detail page.</div>
  </div>
</template>

<script>
export default {
  data() {
    return {
      id: null,
    };
  },
  created() {
    this.id = this.$route.params.id;
  },
};
</script>

<style>
</style>