<template>
  <div>
    <h1>HEADER</h1>
    <AppSearchVue></AppSearchVue>
  </div>
</template>

<script>
import AppSearchVue from './AppSearch.vue'
export default {
  // template -> HTML 형식의 태그
  // script -> 데이터 설정, methods, 외부 컴포넌트 가져오기
  // style -> css 설정
  components: {
    AppSearchVue
  }
}
</script>

<style>

</style>