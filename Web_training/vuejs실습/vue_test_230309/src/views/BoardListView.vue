<template>
  <div>
    <h2>게시판</h2>
    <div>
      <router-link to="/board/1">to page of 1</router-link>
    </div>
    <div>
      <router-link to="/board/2">to page of 2</router-link>
    </div>
    <div>
      <router-link to="/board/456">to page of 456</router-link>
    </div>
    <button @click="go789">GO 789</button>
  </div>
</template>

<script>
export default {
  created() {
    // router : 프로그램, vue에서 설치한 vue router
    // route : 각각의 경로
    console.log(this.$router);
    console.log(this.$route);
  },
  methods: {
    go789() {
      this.$router.push("/board/789");
    }
  }
}
</script>

<style>

</style>