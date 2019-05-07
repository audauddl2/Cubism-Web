<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Cubism</title>
<%@include file="../include/header.jsp"%>
</head>
<body class="hold-transition skin-blue sidebar-mini">
<div class="wrapper">

<!-- Content Wrapper. Contains page content -->
<div class="content-wrapper">
    <!-- Content Header (Page header) -->
    <section class="content-header">
      <h1>
        Game Register
        <small>Preview</small>
      </h1>
      <ol class="breadcrumb">
        <li class="active"><a href="#"><i class="fa fa-dashboard"></i> Upload</a></li>
      </ol>
    </section>
	
	<!-- Main content -->
    <section class="content">
      <div class="row">
        <!-- left column -->
        <div class="col-md-6">
          <!-- general form elements -->
          <div class="box box-primary">
            <div class="box-header with-border">
              <h3 class="box-title">Game Register</h3>
            </div>
            <!-- /.box-header -->
            <!-- form start -->
            <form role="form" action="/cubism/upload?${_csrf.parameterName}=${_csrf.token}" method="post" enctype="multipart/form-data">
              <div class="box-body">
                <div class="form-group">
                  <label>Title</label>
                  <input type="text" class="form-control" name="uploadTitle" placeholder="제목을 입력해 주세요">
                </div>
                <div class="form-group">
                  <label>Content</label>
                  <input type="text" class="form-control" name="uploadContent" placeholder="내용을 입력해 주세요">
                </div>
                <div class="form-group">
                  <label>Flag</label>
                  <input type="text" class="form-control" name="uploadFlag" placeholder="Flag를 설정해 주세요">
                </div>
                <div class="form-group">
                  <label for="exampleInputFile">File input</label>
                  <input type="file" name="uploadFile" id="exampleInputFile">
                </div>
                <!-- 
                <div class="checkbox">
                  <label>
                    <input type="checkbox"> Check me out
                  </label>
                </div>
                 -->
              </div>
              <!-- /.box-body -->
              <div class="box-footer">
                <button type="submit" class="btn btn-primary">Register</button>
              </div>
            </form>
          </div>
          <!-- /.box -->
        </div>
       </div>
      </section>
      <!-- /.content-wrapper -->
	</div>
<!-- ./wrapper -->
</div>
</body>
<footer>
	<%@include file="../include/footer.jsp"%>
</footer>
</html>