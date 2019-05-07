<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <meta http-equiv="refresh" content="300">
	<meta name="_csrf" content="${_csrf.token}"/>
	<meta name="_csrf_header" content="${_csrf.headerName}"/>
	
    <!-- 구글차트 필수 요소 -->
    <!-- jQuery -->
    <script src="https://code.jquery.com/jquery.min.js"></script>
    <!-- google charts -->
    <script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
	<script src="https://www.google.com/jsapi"></script>
	<!-- /구글차트 필수 요소 -->
	<title>Cubism</title>
<%@include file="../include/header.jsp"%>
</head>
  <body class="hold-transition skin-blue sidebar-mini">
  <div class="wrapper">
  <div class="content-wrapper">
  <section class="content-header">
      <h1>
        Chart
        <small>Memory</small>
      </h1>
      <ol class="breadcrumb">
        <li><a href="#"><i class="fa fa-dashboard"></i> Charts</a></li>
        <li><a href="#">1</a></li>
        <li class="active">Memory</li>
      </ol>
    </section>
  	
  	<section class="content">
  	<!-- start -->
		<div class="row">
	        <div class="col-md-12">
	        
			  <!-- AREA CHART -->
	          <div class="box box-primary">
	            <div class="box-header with-border">
	              <i class="fa fa-inbox"></i><strong><h3 class="box-title">기억력 향상도</h3></strong>
	
	              <div class="box-tools pull-right">
	                <button type="button" class="btn btn-box-tool" data-widget="collapse"><i class="fa fa-minus"></i>
	                </button>
	                <button type="button" class="btn btn-box-tool" data-widget="remove"><i class="fa fa-times"></i></button>
	              </div>
	            </div>
		            <div class="box-body">
		              <div class="chart">
						    
						    <div style="text-align:right; width: 90%;">
						        <font size=2>update : <span id="clock"></span></font><br>
						    </div>
						
							<div id="Line_Controls_Chart">
								<!-- 라인 차트 생성할 영역 style="padding:0px 20px 0px 0px;-->
								<div id="lineChartArea" style="padding:0px 20px 0px 0px; margin:20px;"></div>
								<!-- 컨트롤바를 생성할 영역 -->
								<div id="controlsArea" style="padding:0px 20px 0px 0px; margin:20px;"></div>
							</div>
		              </div>
		            </div>
	            	<!-- /.box-body -->
	          	</div>
	          	<!-- /.box box-primary -->
	          	
	        </div>
	        <!-- /.col-md-12 -->
	      </div>
	      <!-- /.row -->
		<!-- end -->
	</section>
	</div>
</div>
</body>
<footer>
	<%@include file="../include/footer.jsp"%>
</footer>

<!-- Mychart -->
<script src="resources/chart/mychart.js"></script>
<!-- /Mychart -->
  	
</html>