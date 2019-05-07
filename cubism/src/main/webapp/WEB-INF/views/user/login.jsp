<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %> 
<%@ taglib prefix="form" uri="http://www.springframework.org/tags/form" %>

<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <title>Cubism | Log in</title>
  <!-- Tell the browser to be responsive to screen width -->
  <meta content="width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no" name="viewport">
  <!-- Bootstrap 3.3.7 -->
  <link rel="stylesheet" href="resources/bower_components/bootstrap/dist/css/bootstrap.min.css">
  <!-- Font Awesome -->
  <link rel="stylesheet" href="resources/bower_components/font-awesome/css/font-awesome.min.css">
  <!-- Ionicons -->
  <link rel="stylesheet" href="resources/bower_components/Ionicons/css/ionicons.min.css">
  <!-- Theme style -->
  <link rel="stylesheet" href="resources/dist/css/AdminLTE.min.css">
  <!-- iCheck -->
  <link rel="stylesheet" href="resources/plugins/iCheck/square/blue.css">

  <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->
  <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
  <!--[if lt IE 9]>
  <script src="https://oss.maxcdn.com/html5shiv/3.7.3/html5shiv.min.js"></script>
  <script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
  <![endif]-->

  <!-- Google Font -->
  <link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Source+Sans+Pro:300,400,600,700,300italic,400italic,600italic">
</head>
<body class="hold-transition login-page" onload="document.f.userId.focus();">
<div class="login-box">
  <div class="login-logo">
    <a href="/cubism"><b>Cubism</b>KPU</a>
  </div>
  <!-- /.login-logo -->
  <div class="login-box-body">
    <p class="login-box-msg">Cubism에 오신것을 환영합니다</p>
    
	<c:url value="/login" var="loginUrl" />
    <form:form name="f" action="${loginUrl}" method="POST">
      <div class="form-group has-feedback">
        <input type="text" id="userId" name="userId" class="form-control" placeholder="Email">
        <span class="glyphicon glyphicon-envelope form-control-feedback"></span>
      </div>
      <div class="form-group has-feedback">
        <input type="password" name="userPw" class="form-control" placeholder="Password">
        <span class="glyphicon glyphicon-lock form-control-feedback"></span>
      </div>
     <%-- <input name="${_csrf.parameterName}" type="hidden" value="${_csrf.token}"/> --%>
     	<div class="col-xs-12">
     	<!-- Error Message Spring Security Reserve -->
			<c:if test="${not empty SPRING_SECURITY_LAST_EXCEPTION}">
			    <font color="red">
			        <p>Your login attempt was not successful due to <br/>
			            ${sessionScope["SPRING_SECURITY_LAST_EXCEPTION"].message}</p>
			        <c:remove var="SPRING_SECURITY_LAST_EXCEPTION" scope="session"/>
			    </font>
			</c:if>
		 
        </div>
      <div class="row">
        <div class="col-xs-8">
          <div class="checkbox icheck">
            <label>
              <input type="checkbox" id="remember_me" name="_spring_security_remember_me"/> Remember Me
            </label>
          </div>
        </div>
        <!-- /.col -->
        <div class="col-xs-4">
          <button type="submit" class="btn btn-primary btn-block btn-flat">Sign In</button>
        </div>
        <!-- /.col -->
      </div>
    </form:form>
    <!-- Error Message----------------------------------------------
   	<div class="row">
    	<div class="col-xs-12">
			<c:if test='${ error eq "login" }'>
            	<p style="color:#FF0000">이메일 혹은 비밀번호를 잘못 입력하셨습니다.</p>
            </c:if>
            <c:if test='${ error eq "duplicate" }'>
            	<p style="color:#FF0000">이미 로그인하고 있는 사용자입니다.</p>
            </c:if>
            <c:if test='${ error eq "not found" }'>
            	<p style="color:#FF0000">등록되지 않은 유저입니다.</p>
            </c:if>
            <c:if test="${ param.logout == 'true' }">
            	<p style="color:#FF0000">로그아웃 되었습니다.</p>
            </c:if>
        </div>
    </div>
     -->
    <br>
    <a href="/cubism/registerPage" class="text-center">회원가입</a>

  </div>
  <!-- /.login-box-body -->
</div>
<!-- /.login-box -->

<!-- jQuery 3 -->
<script src="resources/bower_components/jquery/dist/jquery.min.js"></script>
<!-- Bootstrap 3.3.7 -->
<script src="resources/bower_components/bootstrap/dist/js/bootstrap.min.js"></script>
<!-- iCheck -->
<script src="resources/plugins/iCheck/icheck.min.js"></script>
<script>
  $(function () {
    $('input').iCheck({
      checkboxClass: 'icheckbox_square-blue',
      radioClass: 'iradio_square-blue',
      increaseArea: '20%' /* optional */
    });
  });
</script>
</body>
</html>