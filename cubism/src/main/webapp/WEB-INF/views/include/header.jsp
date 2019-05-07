<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ taglib prefix="sec" uri="http://www.springframework.org/security/tags" %>
<%@ taglib prefix="form" uri="http://www.springframework.org/tags/form" %> 
<%@ page import="org.springframework.security.core.context.SecurityContextHolder" %>
<%@ page import="org.springframework.security.core.Authentication" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
 <title>Cubism   | Dashboard</title>
  <!-- Tell the browser to be responsive to screen width -->
  <meta content="width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no" name="viewport">
  <!-- Bootstrap 3.3.7 -->
  <link rel="stylesheet" href="resources/bootstrap/css/bootstrap.min.css">
  <!-- Font Awesome -->
  <link rel="stylesheet" href="resources/plugins/font-awesome/css/font-awesome.min.css">
  <!-- Ionicons -->
  <link rel="stylesheet" href="resources/plugins/Ionicons/css/ionicons.min.css">
  <!-- Theme style -->
  <link rel="stylesheet" href="resources/dist/css/AdminLTE.min.css">
  <!-- AdminLTE Skins. Choose a skin from the css/skins
       folder instead of downloading all of them to reduce the load. -->
  <link rel="stylesheet" href="resources/dist/css/skins/_all-skins.min.css">
  <!-- Morris chart -->
  <link rel="stylesheet" href="resources/plugins/morris.js/morris.css">
  <!-- jvectormap -->
  <link rel="stylesheet" href="resources/plugins/jvectormap/jquery-jvectormap.css">
  <!-- Date Picker -->
  <link rel="stylesheet" href="resources/plugins/bootstrap-datepicker/bootstrap-datepicker.min.css">
  <!-- Daterange picker -->
  <link rel="stylesheet" href="resources/plugins/bootstrap-daterangepicker/daterangepicker.css">
  <!-- bootstrap wysihtml5 - text editor -->
  <link rel="stylesheet" href="resources/plugins/bootstrap-wysihtml5/bootstrap3-wysihtml5.min.css">

  
  <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->
  <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
  <!--[if lt IE 9]>
  <script src="https://oss.maxcdn.com/html5shiv/3.7.3/html5shiv.min.js"></script>
  <script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
  <![endif]-->

  <!-- Google Font -->
  <link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Source+Sans+Pro:300,400,600,700,300italic,400italic,600italic">
</head>
<%
    Authentication auth = SecurityContextHolder.getContext().getAuthentication();
    Object principal = auth.getPrincipal();

%>

<body class="hold-transition skin-blue sidebar-mini">
<div class="wrapper">

  <header class="main-header">
    <!-- Logo -->
    <a href="/cubism" class="logo">
      <!-- mini logo for sidebar mini 50x50 pixels -->
      <span class="logo-mini"><b>C</b>BM</span>
      <!-- logo for regular state and mobile devices -->
      <span class="logo-lg"><b>Cubism</b></span>
    </a>
    
    <!-- Header Navbar: style can be found in header.less -->
    <nav class="navbar navbar-static-top">
      <!-- Sidebar toggle button-->
      <a href="#" class="sidebar-toggle" data-toggle="push-menu" role="button">
        <span class="sr-only">Toggle navigation</span>
      </a>

      <div class="navbar-custom-menu">
        <ul class="nav navbar-nav">     
          <!-- User Account: style can be found in dropdown.less -->
          <li class="dropdown user user-menu">
            <a href="#" class="dropdown-toggle" data-toggle="dropdown">
              <img src="resources/dist/img/profile.jpg" class="user-image" alt="User Image">
              
				<sec:authorize access="isAuthenticated()">         	
                  		<span class="hidden-xs">
                  			<sec:authentication property="principal.username"/>
                  		</span> 
	            </sec:authorize>
				
                <sec:authorize access="isAnonymous()">
					<span class="hidden-xs">Please Check Login</span>
				</sec:authorize>
				  
            </a>
            <ul class="dropdown-menu">
              <!-- User image -->
              <li class="user-header">
                <img src="resources/dist/img/profile.jpg" class="img-circle" alt="User Image">
                
				<sec:authorize access="isAuthenticated()"> 
	            	<p>
                  		<sec:authentication property="principal.username"/>
                  		<small>Member since January. 2019</small>
                	</p> 
	            </sec:authorize>
	
				<sec:authorize access="isAnonymous()">
				<p>
                  	Please Check Login
                </p>
				</sec:authorize>
              </li>       
              
              <!-- Menu Body -->
              <!--
              <li class="user-body">
                <div class="row">
                  <div class="col-xs-4 text-center">
                    <a href="#">Followers</a>
                  </div>
                  <div class="col-xs-4 text-center">
                    <a href="#">Sales</a>
                  </div>
                  <div class="col-xs-4 text-center">
                    <a href="#">Friends</a>
                  </div>
                </div>
                -- /.row -- 
              </li>
              -->
              <!-- Menu Footer-->
              <li class="user-footer">
              <sec:authorize access="isAuthenticated()">
					<div class="pull-left">
	                  <a href="#" class="btn btn-default btn-flat">Profile</a>
	                </div>
					 
		            <form action="${pageContext.request.contextPath}/logout" method="POST">
		            	<input type="hidden" name="${_csrf.parameterName}" value="${_csrf.token}" />
		            	<div class="pull-right">	
		            		<input class="btn btn-default btn-flat" type="submit" value="Sign out" /> 
		            	</div>
		            </form>

	                
				</sec:authorize>
				<sec:authorize access="isAnonymous()">
				<div class="pull-right">
                  <a href="<c:url value="/loginPage" />" class="btn btn-default btn-flat">Sign in</a>
                </div>
				</sec:authorize>				
              </li>
            </ul>
          </li>
          
          
          <!-- Control Sidebar Toggle Button -->
          <li>
            <a href="#" data-toggle="control-sidebar"><i class="fa fa-gears"></i></a>
          </li>
        </ul>
      </div>
    </nav>
  </header>
  <!-- Left side column. contains the logo and sidebar -->
  <aside class="main-sidebar">
    <!-- sidebar: style can be found in sidebar.less -->
    <section class="sidebar">
      <!-- Sidebar user panel -->
      <div class="user-panel">
        <div class="pull-left image">
          <img src="resources/dist/img/profile.jpg" class="img-circle" alt="User Image">
        </div>
        <div class="pull-left info">
        	
			<sec:authorize access="isAuthenticated()"> 
	        	<p>
	        		<sec:authentication property="principal.username"/>
	        	</p>
	        	<a href="#"><i class="fa fa-circle text-success"></i> Online</a> 
	        </sec:authorize>
				
            <sec:authorize access="isAnonymous()">
				<p>Please Check Login</p>
	        	<a href="/cubism/loginPage"><i class="fa fa-circle text-fail"></i> Offline</a>
			</sec:authorize>
			
        </div>
      </div>
      
      <!-- search form 
      <form action="#" method="get" class="sidebar-form">
        <div class="input-group">
          <input type="text" name="q" class="form-control" placeholder="Search...">
          <span class="input-group-btn">
                <button type="submit" name="search" id="search-btn" class="btn btn-flat"><i class="fa fa-search"></i>
                </button>
              </span>
        </div>
      </form>
      -->
      <!-- /.search form -->
      
      
      <!-- sidebar menu: : style can be found in sidebar.less -->
      <ul class="sidebar-menu" data-widget="tree">
        <li class="header">MAIN NAVIGATION</li>
        
        <li> <!-- 지울 부분인데 class부분을 따라가야할듯 싶다 일단 보류 fa-dashboard -->
          <a href="/cubism">
            <i class="fa fa-dashboard"></i> <span>Home</span>
          </a>
        </li>
        
        <li>
          <a href="/cubism/calendar">
            <i class="fa fa-calendar"></i> <span>Calendar</span>
          </a>
        </li>
        
        
        <li class="treeview">
          <a href="#">
            <i class="fa fa-pie-chart"></i>
            <span>Memory Charts</span>
            <span class="pull-right-container">
              <i class="fa fa-angle-left pull-right"></i>
            </span>
          </a>
          <ul class="treeview-menu">
            <li><a href="/cubism/chartview"><i class="fa fa-circle-o"></i> Order Game</a></li>
            <li><a href="#"><i class="fa fa-circle-o"></i> GuGuDan Game</a></li>
            <!-- Non Active  
            <li><a href="#"><i class="fa fa-circle-o"></i> 3</a></li>
            <li><a href="#"><i class="fa fa-circle-o"></i> 4</a></li>
          	-->
          </ul>
        </li>
        
        <!-- 
        <li class="treeview">
          <a href="#">
            <i class="fa fa-table"></i> <span>Tables</span>
            <span class="pull-right-container">
              <i class="fa fa-angle-left pull-right"></i>
            </span>
          </a>
          <ul class="treeview-menu">
            <li><a href="pages/tables/simple.html"><i class="fa fa-circle-o"></i> Simple tables</a></li>
            <li><a href="pages/tables/data.html"><i class="fa fa-circle-o"></i> Data tables</a></li>
          </ul>
        </li>
 		-->
 		
        <li class="treeview">
          <a href="#">
            <i class="fa fa-share"></i> <span>Upload</span>
            <span class="pull-right-container">
              <i class="fa fa-angle-left pull-right"></i>
            </span>
          </a>
          <ul class="treeview-menu">
          
          	<!-- <li><a href="/cubism/upload"><i class="fa fa-circle-o"></i> 게임등록</a></li> -->
          	
            <li><a href="/cubism/uploadList"><i class="fa fa-circle-o"></i> Order Game</a></li>

            <li><a href="/cubism/GGuploadList"><i class="fa fa-circle-o"></i> GuGuDan Game</a></li>
            <!-- Non Active 
            <li class="treeview">
              <a href="#"><i class="fa fa-circle-o"></i> 게임 이름3
                <span class="pull-right-container">
                  <i class="fa fa-angle-left pull-right"></i>
                </span>
              </a>
              <ul class="treeview-menu">
                <li><a href="#"><i class="fa fa-circle-o"></i> 게임 이름3-1</a></li>
                <li class="treeview">
                  <a href="#"><i class="fa fa-circle-o"></i> 게임 이름3-1
                    <span class="pull-right-container">
                      <i class="fa fa-angle-left pull-right"></i>
                    </span>
                  </a>
                  <ul class="treeview-menu">
                    <li><a href="#"><i class="fa fa-circle-o"></i> 게임 이름3-2</a></li>
                    <li><a href="#"><i class="fa fa-circle-o"></i> 게임 이름3-2</a></li>
                  </ul>
                </li>
              </ul>
            </li>
            -->
          </ul>
        </li>
        
        
        
        <li><a href="https://www.kpu.ac.kr"><i class="fa fa-book"></i> <span>Documentation</span></a></li>
        <li class="header">LABELS</li>
        <li><a href="#"><i class="fa fa-circle-o text-red"></i> <span>Important</span></a></li>
        <li><a href="#"><i class="fa fa-circle-o text-yellow"></i> <span>Warning</span></a></li>
        <li><a href="#"><i class="fa fa-circle-o text-aqua"></i> <span>Information</span></a></li>
      </ul>
    </section>
    <!-- /.sidebar -->
  </aside>

