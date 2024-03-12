<template>

  <h3>模板语法</h3>
  <p>{{msg}}</p>
  <p>{{hello}}</p>
  每个{{}}可以放置单行的单一表达式，可以被求值的表达式，
  <p>{{number+1}}</p>
  <p>{{ok?"Yes":"No"}}</p>
  <p>{{message.split("").reverse().join(' ')}}</p>

  无效的：
<!--  这是一个语句，不是表达式-->
<!--  <p>{{var a=1}}</p> -->
<!--  条件控制也不支持，请使用三元表达式-->
<!--  {{if(ok){return message}}}-->

  防止原始Html
  <p>{{rawHtml}}</p>
  <p v-html="rawHtml"></p>


</template>



<script>
export default {
  data(){
    return {
      msg:"神奇的语法",
      hello:"hello world",
      number:10,
      ok:1,
      message:"大家好",
      rawHtml:"<a href='https://itbaizhan.com'>百战程序员</a>"
    }
  }
}

</script>




