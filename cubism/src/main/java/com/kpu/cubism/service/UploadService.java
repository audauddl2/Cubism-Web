package com.kpu.cubism.service;

import java.util.Iterator;
import java.util.List;
import java.util.Map;

import javax.servlet.http.HttpServletRequest;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;
import org.springframework.web.multipart.MultipartHttpServletRequest;

import com.kpu.cubism.common.FileUtils;
import com.kpu.cubism.dao.UploadDao;
import com.kpu.cubism.vo.UploadVo;


@Service
public class UploadService {
	
	
	@Autowired
	FileUtils fileUtils;
	
	@Autowired
	UploadDao uploadDAO;
	
	
	
	/******************
	 * 파일 업로드 
	 * @return 등록 결과
	 ******************/
	public boolean getUploadInsert(UploadVo uploadVO, Map<String,Object> map, HttpServletRequest request) throws Exception{
		
		//System.out.println("UploadService Start =================================================");
		MultipartHttpServletRequest multi = (MultipartHttpServletRequest)request;
		Iterator<String> iter = multi.getFileNames();
		MultipartFile multipartFile = null;
		
		while(iter.hasNext()) {
			multipartFile = multi.getFile(iter.next());
			if(multipartFile.isEmpty() == false) {
				System.out.println("===================================");
				System.out.println("name " + multipartFile.getName());
				System.out.println("filename " + multipartFile.getOriginalFilename());
				System.out.println("size " + multipartFile.getSize());
				System.out.println("===================================");
				
				List<Map<String, Object>> list = fileUtils.parseInsertFileInfo(uploadVO ,request);
				
				System.out.println("list size : " + list.size());
				
				if(list.size() != 0) {
					for(int i = 0, size = list.size(); i<size; i++) {
						uploadDAO.insertFile(list.get(i));
					}
				}
			} else {
				System.out.println("파일을 찾을 수 없습니다...");
			}
		}
			
		System.out.println("Upload Service end 한글테스트 =================================================");
		return true;
	}

	public List<UploadVo> getUploadList(UploadVo vo) {
		System.out.println("Service List Start =================================================");
		return uploadDAO.getUploadList(vo);
	}
	public List<UploadVo> getGGUploadList(UploadVo vo) {
		System.out.println("Service List Start =================================================");
		return uploadDAO.getGGUploadList(vo);
	}

}
