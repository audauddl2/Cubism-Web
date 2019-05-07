<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Cubism</title>
	<%@include file="../include/header.jsp"%>
	
<!-- Iframe 반응형 

padding-bottom : 56.25%; -> 16:9 비율의 경우
				 75%	 -> 4:3 비율의 경우

<style>
.countsort{
	position : relative;
	overflow: hidden;
	max-width : 100%;
	height : 0;
	padding-bottom : 56.25%;
}

.frame{
	position : absolute;
	top : 0;
	left : 0;
	width : 100%;
	height : 100%;
}
</style>
-->

</head>
<body>
	<!-- Iframe 반응형 
	<div class="countsort">
		<iframe class="frame" name="main" src="./main" scrolling="no" frameborder="0" allowfullscreen="" allowtransparency="true"></iframe>
	</div>
	 -->
	<%@include file="main.jsp"%>

</body>
<footer>
	<%@include file="../include/footer.jsp"%>
</footer>

</html>