<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="form" uri="http://www.springframework.org/tags/form" %>
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <!-- csrf 토큰 -->
  <meta id="_csrf" name="_csrf" content="${_csrf.token}" />
  <meta id="_csrf_header" name="_csrf_header" content="${_csrf.headerName}" />
  

  <!-- <meta http-equiv="X-UA-Compatible" content="IE=edge"> -->
  <title>Cubism | Registration</title>
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
  <!-- iCheck for checkboxes and radio inputs -->
  <link rel="stylesheet" href="resources/plugins/iCheck/all.css">

  <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->
  <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
  <!--[if lt IE 9]>
  <script src="https://oss.maxcdn.com/html5shiv/3.7.3/html5shiv.min.js"></script>
  <script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
  <![endif]-->
  <!-- Google Font -->
  <link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Source+Sans+Pro:300,400,600,700,300italic,400italic,600italic">
<%@ include file="../include/include-header.jspf" %>
</head>
<body class="hold-transition register-page">
<div class="register-box">
  <div class="register-logo">
    <a href="/cubism"><b>Cubism</b>KPU</a>
  </div>

  <div class="register-box-body">
    <p class="login-box-msg">Cubism에 오신것을 환영합니다</p>
	
	
    <form:form id="frm" method="POST">
	  <div class="form-group has-feedback" id="divInputId">
	  	<input type="email" id="userId" name="userId" class="form-control" placeholder="Email">
	  	<span class="glyphicon glyphicon-envelope form-control-feedback"></span>
	  </div>
      <div class="form-group has-feedback" id="divInputPw">
        <input type="password" id="userPw" name="userPw" class="form-control" placeholder="Password">
        <span class="glyphicon glyphicon-lock form-control-feedback"></span>
      </div>
      <div class="form-group has-feedback">
        <input type="text" id="userName" name="userName" class="form-control" placeholder="Name">
        <span class="glyphicon glyphicon-user form-control-feedback"></span>
      </div>
      <div class="form-group has-feedback">
        <input type="text" id="userAge" name="userAge" class="form-control" placeholder="Age">
        <span class="glyphicon glyphicon-log-in form-control-feedback"></span>
      </div>
      <!-- radio -->
      <div class="row" style="margin-bottom:7px;">
      	<div class="col-xs-6">
	      <label>
	      	Male
	      	<input type="radio" id="userSex" name="userSex" class="flat-red" value="Male" checked>
	      </label>
	      <label>
	      	Female
	      	<input type="radio" id="userSex" name="userSex"  class="flat-red" value="Female">     
	      </label>
	  	</div>
		<div class="col-xs-6">
			<a href="#" id="user_id_checkBtn" class="btn btn-primary btn-block btn-flat">회원 등록 중복검사</a>
	    </div>
      </div>
      <div class="row">
      
        <div class="col-xs-8">
        <a href="/cubism/loginPage" class="text-center">이미 가입한 계정이 있습니다</a>
        
          <!-- I agree to the terms --------------------------------------
          <div class="checkbox icheck">
            <label>
              <input type="checkbox"> I agree to the <a href="#">terms</a>
            </label>
          </div>
          -->
        </div>
        <!-- /.col -->
        <div class="col-xs-4">
        	<a href="#" id="signUpBtn" class="btn btn-primary btn-block btn-flat">Register</a>
        </div>
        <!-- /.col -->
      </div>
    </form:form>
    
  </div>
  <!-- /.form-box -->
</div>
<!-- /.register-box -->

<!-- jQuery 3 -->
<script src="resources/bower_components/jquery/dist/jquery.min.js"></script>
<!-- Bootstrap 3.3.7 -->
<script src="resources/bower_components/bootstrap/dist/js/bootstrap.min.js"></script>
<!-- iCheck -->
<script src="resources/plugins/iCheck/icheck.min.js"></script>
<!-- User Register -->
<script src="resources/user/myuser.js"></script>
<!-- User Check -->
<script src="resources/user/usercheck.js"></script>

<script>
  $(function () {
    $('input').iCheck({
      checkboxClass: 'icheckbox_square-blue',
      radioClass: 'iradio_square-blue',
      increaseArea: '20%' /* optional */
    });
    
  	//Flat red color scheme for iCheck
    $('input[type="checkbox"].flat-red, input[type="radio"].flat-red').iCheck({
      checkboxClass: 'icheckbox_flat-green',
      radioClass   : 'iradio_flat-green'
    });
    
  });
  
</script>
</body>
</html>