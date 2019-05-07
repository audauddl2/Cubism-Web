package com.kpu.cubism.vo;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class UploadVo {
	
	private int uploadIdx;					// 업로드 파일 Index
	private String uploadTitle;				// 업로드 파일 제목
	private String uploadContent;			// 업로드 파일 내용
	private String uploadFileName;			// 업로드 파일 이름
	private String uploadFileRealName;		// 업로드 파일 진짜 이름
	private int uploadFileSize;				// 업로드 파일 크기
	private String uploadFlag;				// 업로드 파일 구분자(OR, GG etc)
	private String uploadWriter;			// 등록자
	private String uploadDate;				// 업로드 일시
	private String uploadModfier;			// 수정자
	private String uploadModifyDate;		// 수정 일시
	private String useYN;					// 사용 여부(Y,N)
	public int getUploadIdx() {
		return uploadIdx;
	}
	public void setUploadIdx(int uploadIdx) {
		this.uploadIdx = uploadIdx;
	}
	public String getUploadTitle() {
		return uploadTitle;
	}
	public void setUploadTitle(String uploadTitle) {
		this.uploadTitle = uploadTitle;
	}
	public String getUploadContent() {
		return uploadContent;
	}
	public void setUploadContent(String uploadContent) {
		this.uploadContent = uploadContent;
	}
	public String getUploadFileName() {
		return uploadFileName;
	}
	public void setUploadFileName(String uploadFileName) {
		this.uploadFileName = uploadFileName;
	}
	public String getUploadFileRealName() {
		return uploadFileRealName;
	}
	public void setUploadFileRealName(String uploadFileRealName) {
		this.uploadFileRealName = uploadFileRealName;
	}
	public int getUploadFileSize() {
		return uploadFileSize;
	}
	public void setUploadFileSize(int uploadFileSize) {
		this.uploadFileSize = uploadFileSize;
	}
	public String getUploadFlag() {
		return uploadFlag;
	}
	public void setUploadFlag(String uploadFlag) {
		this.uploadFlag = uploadFlag;
	}
	public String getUploadWriter() {
		return uploadWriter;
	}
	public void setUploadWriter(String uploadWriter) {
		this.uploadWriter = uploadWriter;
	}
	public String getUploadDate() {
		return uploadDate;
	}
	public void setUploadDate(String uploadDate) {
		this.uploadDate = uploadDate;
	}
	public String getUploadModfier() {
		return uploadModfier;
	}
	public void setUploadModfier(String uploadModfier) {
		this.uploadModfier = uploadModfier;
	}
	public String getUploadModifyDate() {
		return uploadModifyDate;
	}
	public void setUploadModifyDate(String uploadModifyDate) {
		this.uploadModifyDate = uploadModifyDate;
	}
	public String getUseYN() {
		return useYN;
	}
	public void setUseYN(String useYN) {
		this.useYN = useYN;
	}
	
	
	
}
