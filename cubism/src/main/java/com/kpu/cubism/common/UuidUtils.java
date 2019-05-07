package com.kpu.cubism.common;

import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.UUID;

import javax.servlet.http.HttpServletRequest;

import org.springframework.stereotype.Component;
import org.springframework.web.multipart.MultipartFile;
import org.springframework.web.multipart.MultipartHttpServletRequest;

import com.kpu.cubism.vo.UploadVo;

@Component("uuidUtils")
public class UuidUtils {

	//중복 파일 제거
	public static String getUuid() {
		
		String userKey = "";
		
		userKey = UUID.randomUUID().toString();
		
		return userKey;
	}
	
}
