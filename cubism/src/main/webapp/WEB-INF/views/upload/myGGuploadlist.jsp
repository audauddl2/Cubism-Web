<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Cubism</title>
<%@include file="../include/header.jsp"%>

<script>
   var result = "${msg}";
        if(result == "regsuccess"){
            alert('등록 성공');
        }
</script>

</head>
<body class="hold-transition skin-blue sidebar-mini">
<div class="wrapper">

<!-- Content Wrapper. Contains page content -->
<div class="content-wrapper">
    <!-- Content Header (Page header) -->
    <section class="content-header">
      <h1>
        GuGuDanGame
        <small>List</small>
      </h1>
      <ol class="breadcrumb">
        <li><a href="#"><i class="fa fa-dashboard"></i> Upload</a></li>
        <li class="active">OrderGame</li>
        
      </ol>
    </section>
	
	<!-- Main content -->
    <section class="content">
      <div class="row">
        <!-- left column -->
        <div class="col-md-12">
          <!-- general form elements -->
          <div class="box box-primary">
            <div class="box-header with-border">
              <h3 class="box-title">GuGuDanGame Version List</h3>
            </div>
            <!-- /.box-header -->
            
            <div class="box-body">
              <table id="example2" class="table table-bordered table-hover">
                <thead>
                <tr>
                  <th>No</th>
                  <th>Title</th>
                  <th>Date</th>
                  <th>Register</th>
                  <th>Content</th>
                </tr>
                </thead>
                <tbody>
                	<!-- Memory 출력 -->
			        <c:choose>
			            <c:when test="${fn:length(list) > 0}">
			                <c:forEach items="${list}" var="list" varStatus="rowcnt">
			                    <tr>
			                        <td>${list.uploadIdx}</td>
			                        <td>${list.uploadTitle}</td>
			                        <td>${list.uploadDate}</td>
			                        <td>${list.uploadWriter}</td>
			                        <td>${list.uploadContent}</td>
			                    </tr>
			                </c:forEach>
			            </c:when>
			            <c:otherwise>
			                <tr>
			                    <td colspan="4">조회된 결과가 없습니다.</td>
			                </tr>
			            </c:otherwise>
			        </c:choose>
            	</tbody>
            	</table>
            </div>
            
            <div class="box-footer">
            	<a href="/cubism/upload"><button type="submit" class="btn btn-primary">Game Register</button></a>
          	</div>
          </div>
          <!-- /.box -->
          
        </div>
       </div>
      </section>
      <!-- /.content-wrapper -->
	</div>
<!-- ./wrapper -->
</div>
<!-- jQuery 3 -->
<script src="resources/plugins/jquery/jquery.min.js"></script>
<!-- jQuery UI 1.11.4 -->
<script src="resources/plugins/jquery-ui/jquery-ui.min.js"></script>
<!-- page script -->
<script>
  $(function () {
    $('#example1').DataTable()
    $('#example2').DataTable({
      'paging'      : true,
      'lengthChange': false,
      'searching'   : false,
      'ordering'    : true,
      'info'        : false,
      'autoWidth'   : false
    })
  })
</script>
</body>
<%@include file="../include/footer.jsp"%>
</html>