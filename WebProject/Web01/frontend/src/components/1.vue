<template>
  属性绑定 v-bind:属性名="属性值"
  <div v-bind:class="msg">测试</div>
  简写
  <div :class="msg">测试</div>
  如果属性值是null,会把该属性移除
  布尔型属性
  <button :disabled="isButtonDisabled"></button>
  动态绑定多个值
  <div v-bind="objectOfAttrs">测试</div>
</template>

<script>
  export default{
    data() {
      return{
        msg:"active",
        isButtonDisabled:true,
        objectOfAttrs:{
          id:"appid",
          class:"appidclass"
        }
      }
    }
  }
</script>

<style>

</style>