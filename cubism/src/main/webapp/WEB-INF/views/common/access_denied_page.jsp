<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ taglib prefix="sec" uri="http://www.springframework.org/security/tags" %>
<%@ taglib prefix="form" uri="http://www.springframework.org/tags/form" %> 
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %> 

<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
 <title>Cubism   | Dashboard</title>
	<!-- jQuery Submit Function --> 
	<script src="<c:url value='resources/common/common.js'/>" charset="UTF-8"></script>
</head>
<body>
	<script type="text/javascript">  
	alert("접근 권한이 없습니다");
	document.location.href = history.back(); 
	</script>
</body>
</html> 